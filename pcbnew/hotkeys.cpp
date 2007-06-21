    /***************/
    /* hotkeys.cpp */
    /***************/

#include "fctsys.h"

#include "gr_basic.h"

#include "common.h"
#include "pcbnew.h"
#include "id.h"

#include "protos.h"

/* Routines locales */

/* variables externes */

/***********************************************************/
void WinEDA_PcbFrame::OnHotKey(wxDC * DC, int hotkey,
                    EDA_BaseStruct * DrawStruct)
/***********************************************************/
/* Gestion des commandes rapides (Raccourcis claviers) concernant l'element
sous le courseur souris
 Les majuscules/minuscules sont indifferenciees
    touche DELETE: Effacement (Module ou piste selon commande en cours)
    touche V: Place via en cours de trace de piste
    touche R: Rotation module
    touche S: Change couche module (Composant <-> Cuivre)
    touche M: Start Move module
    touche G: Start Drag module
*/
{
    bool PopupOn = GetScreen()->m_CurrentItem  &&
                GetScreen()->m_CurrentItem->m_Flags;
    bool ItemFree = (GetScreen()->m_CurrentItem == 0 )  ||
                (GetScreen()->m_CurrentItem->m_Flags == 0);

    if ( hotkey == 0 ) return;

    MODULE* module = NULL;

    switch (hotkey)
    {
    case WXK_DELETE:
    case WXK_NUMPAD_DELETE:
        OnHotkeyDeleteItem(DC, DrawStruct);
        break;

    case WXK_BACK:
    { 
        if( m_ID_current_state == ID_TRACK_BUTT && 
                     GetScreen()->m_Active_Layer <= CMP_N )
        {
            bool ItemFree = (GetScreen()->m_CurrentItem == NULL ) || 
                    (GetScreen()->m_CurrentItem->m_Flags == 0);
            if ( ItemFree )
            {
                //no track is currently being edited - select a segment and remove it.
                DrawStruct = PcbGeneralLocateAndDisplay();
                //don't let backspace delete modules!!
                if ( DrawStruct && (DrawStruct->m_StructType == TYPETRACK
                                    || DrawStruct->m_StructType == TYPEVIA))
                    Delete_Segment(DC, (TRACK*)DrawStruct);
                GetScreen()->SetModify();
            }
            else if ( GetScreen()->m_CurrentItem->m_StructType == TYPETRACK  )
            {
                //then an element is being edited - remove the last segment.
                GetScreen()->m_CurrentItem =
                        Delete_Segment(DC, (TRACK*)GetScreen()->m_CurrentItem);
                GetScreen()->SetModify();
            }
        }
        break; 
    }
    
    case WXK_END:
        DrawPanel->MouseToCursorSchema();
        End_Route( (TRACK *) (GetScreen()->m_CurrentItem), DC);
        break;
		
	case (int('f') + GR_KB_CTRL) :
	case (int('F') + GR_KB_CTRL) :
	case 1030:{ // f = letter 6 in the alphabet + 1024 = 1030
			wxCommandEvent evt; 
			evt.SetId(ID_FIND_ITEMS); 
			Process_Special_Functions(evt); 
		}
		break; 
	
    case 'v':   // Switch to alternate layer and Place a via if a track is in progress
    case 'V':
        if ( m_ID_current_state != ID_TRACK_BUTT ) return;
        if ( ItemFree )
        {
            Other_Layer_Route( NULL, DC);
            break;
        }
        if ( GetScreen()->m_CurrentItem->m_StructType != TYPETRACK )
            return;
        if ( (GetScreen()->m_CurrentItem->m_Flags & IS_NEW) == 0 )
            return;
        Other_Layer_Route( (TRACK *) GetScreen()->m_CurrentItem, DC);
        if ( DisplayOpt.ContrastModeDisplay )
            GetScreen()->SetRefreshReq();
        break;

	case 'o':
	case 'O':	
	case (int('o') + GR_KB_CTRL) :
	case (int('O') + GR_KB_CTRL) :
	case 1039: //o is the 15th letter in the alphabet + 1024 = 1039
		if( hotkey & GR_KB_CTRL ){
			//try not to duplicate save, load code etc.
			wxCommandEvent evt; 
			evt.SetId(ID_LOAD_FILE); 
			Files_io(evt); 
		}
		break; 
    case 'r':   // Rotation
    case 'R':
        if ( ItemFree )
            module = Locate_Prefered_Module(m_Pcb, 
                CURSEUR_ON_GRILLE | IGNORE_LOCKED | MATCH_LAYER );
        else if (GetScreen()->m_CurrentItem->m_StructType == TYPEMODULE)
        {
            module = (MODULE*)GetScreen()->m_CurrentItem;
            // @todo: might need to add a layer check in if() below
            if( module->IsLocked() )
                module = 0; // do not move it.
        }
        if ( module )
        {
            GetScreen()->m_CurrentItem = module;
            module->Display_Infos(this);
            Rotate_Module(DC, module, 900, TRUE);
        }
        break;

    case 's':   // move to other side
    case 'S':
	case (int('s') + GR_KB_CTRL) :
	case (int('S') + GR_KB_CTRL) :
	case 1043: //as before, 19th letter..
		if(  hotkey & GR_KB_CTRL ){
			//try not to duplicate save, load code etc.
			wxCommandEvent evt; 
			evt.SetId(ID_SAVE_BOARD); 
			Files_io(evt); 
		}else{
			if ( ItemFree )
				module = Locate_Prefered_Module(m_Pcb, 
					CURSEUR_ON_GRILLE | IGNORE_LOCKED | MATCH_LAYER );
			else if (GetScreen()->m_CurrentItem->m_StructType == TYPEMODULE)
			{
				module = (MODULE*)GetScreen()->m_CurrentItem;
				// @todo: might need to add a layer check in if() below
				if( module->IsLocked() )
					module = 0; // do not move it.
			}
			if ( module )
			{
				GetScreen()->m_CurrentItem = module;
				module->Display_Infos(this);
				Change_Side_Module(module, DC);
			}
		}
        break;
        
    case 'L':   // toggle module "MODULE_is_LOCKED" status:
    case 'l':
        // get any module, locked or not locked and toggle its locked status
        module = Locate_Prefered_Module( m_Pcb, CURSEUR_ON_GRILLE | MATCH_LAYER );
        if( module )
        {
            GetScreen()->m_CurrentItem = module;
            module->SetLocked( !module->IsLocked() );
            module->Display_Infos(this);
        }
        break;
        
    case 'g':
    case 'G':   // Start move (and drag) module
        g_Drag_Pistes_On = TRUE;
        // fall through

    case 'm':
    case 'M':   // Start move module
        if ( PopupOn ) break;
        module = Locate_Prefered_Module( m_Pcb, 
            CURSEUR_ON_GRILLE | IGNORE_LOCKED | MATCH_LAYER );
        if( module )
        {
            GetScreen()->m_CurrentItem = module;
            module->Display_Infos(this);
            StartMove_Module( module, DC);
        }
        break;
    }
}


/***********************************************************/
void WinEDA_ModuleEditFrame::OnHotKey(wxDC * DC, int hotkey,
                    EDA_BaseStruct * DrawStruct)
/***********************************************************/
/* Gestion des commandes rapides (Raccourcis claviers) concernant l'element
sous le courseur souris
 Les majuscules/minuscules sont indifferenciees
*/
{
bool PopupOn = GetScreen()->m_CurrentItem  &&
            GetScreen()->m_CurrentItem->m_Flags;
    if ( hotkey == 0 ) return;

    switch (hotkey)
    {
        case WXK_DELETE:
        case WXK_NUMPAD_DELETE:
            if ( PopupOn ) break;
            break;

        case 'r':   // Rotation
        case 'R':
            break;

        case 'y':   // Mirror Y (drawlibpart)
        case 'Y':
            break;

        case 'x':   // Mirror X (drawlibpart)
        case 'X':
            break;

        case 'n':
        case 'N':   // Orient 0, no mirror (drawlibpart)
            break;

        case 'm':
        case 'M':   // Start move drawlibpart
            if ( PopupOn ) break;
            break;
    }
}

/******************************************************************************/
bool WinEDA_PcbFrame::OnHotkeyDeleteItem(wxDC * DC, EDA_BaseStruct * DrawStruct)
/******************************************************************************/
/* Efface l'item pointe par la souris, en reponse a la touche "Del"
    Effet dependant de l'outil selectionne:
        Outil trace de pistes
            Efface le segment en cours ou la piste si pas d'element
        Outil module:
            Efface le module.
*/
{
bool ItemFree = (GetScreen()->m_CurrentItem == NULL )  ||
            (GetScreen()->m_CurrentItem->m_Flags == 0);

    switch ( m_ID_current_state )
        {
        case ID_TRACK_BUTT:
            if ( GetScreen()->m_Active_Layer > CMP_N ) return FALSE;
            if ( ItemFree )
            {
                DrawStruct = PcbGeneralLocateAndDisplay();
                if ( DrawStruct && DrawStruct->m_StructType != TYPETRACK ) return FALSE;
                Delete_Track(DC, (TRACK*)DrawStruct);
            }
            else if ( GetScreen()->m_CurrentItem->m_StructType == TYPETRACK  )
            {
            GetScreen()->m_CurrentItem =
                Delete_Segment(DC, (TRACK*)GetScreen()->m_CurrentItem);
            GetScreen()->SetModify();
            return TRUE;
            }
            break;

        case ID_COMPONENT_BUTT:
            if ( ItemFree )
            {
                MODULE * module = Locate_Prefered_Module(m_Pcb, CURSEUR_ON_GRILLE);
                if ( module == NULL ) return FALSE;
                if( ! IsOK(this, _("Delete module?")) ) return FALSE;
                RemoveStruct(module, DC);
            }
            else return FALSE;
            break;

        default:
            return FALSE;
        }

    GetScreen()->SetModify();
    GetScreen()->m_CurrentItem = NULL;
    return TRUE;
}
