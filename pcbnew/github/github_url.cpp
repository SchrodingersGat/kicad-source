/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2013 SoftPLC Corporation, Dick Hollenbeck <dick@softplc.com>
 * Copyright (C) 2017 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "github_url.h"

#include <wx/regex.h>
 
// Magic string for validating GitHub URL
const wxString GITHUB_URL_REGEX  = "^(?:https?:\\/*)?(?:www\\.)?github\\.com\\/([^\\/]*)\\/([^\\/]*)(?:\\/tree\\/master)?(.*)$";

enum GitHubRegexMatchIndex
{
    GITHUB_MATCH_FULL = 0,  // Entire string match
    GITHUB_MATCH_ORG,       // Match organization e.g. 'KiCad'
    GITHUB_MATCH_REPO,      // Match repo name e.g. 'footprints'
    GITHUB_MATCH_SUBDIR,    // Match remaining subdir string from GitHub URL
};

#define GITHUB_MATCH_COUNT 4

GITHUB_URL::GITHUB_URL( const wxString& aUrl )
{
    SetUrl( aUrl );
}

bool GITHUB_URL::SetUrl( const wxString& aUrl )
{
    wxRegEx reg( GITHUB_URL_REGEX, wxRE_ADVANCED | wxRE_ICASE );
    
    if( !reg.IsValid() || !reg.Matches( aUrl ) )
        return false;
    
    if( reg.GetMatchCount() < GITHUB_MATCH_COUNT )
        return false;
        
    // Extract data
    m_repoOrg    = reg.GetMatch( aUrl, GITHUB_MATCH_ORG );
    m_repoName   = reg.GetMatch( aUrl, GITHUB_MATCH_REPO );
    m_repoSubdir = reg.GetMatch( aUrl, GITHUB_MATCH_SUBDIR );
    
    if( m_repoSubdir.StartsWith( "/" ) )
    {
        m_repoSubdir = m_repoSubdir.Remove( 0, 1 );
    }

    return IsValid();
}

bool GITHUB_URL::IsValid() const
{
    return !m_repoOrg.IsEmpty() && !m_repoName.IsEmpty();
}

/**
 * Recreate the entire github URL, correctly formatted
 */
wxString GITHUB_URL::GetFullURL( bool aIncludeTree ) const
{
    wxString url = "https://github.com/";
    
    url += m_repoOrg + "/" + m_repoName;
    
    if( aIncludeTree )
    {
        url += "/tree/master";
    }
    
    if( !m_repoSubdir.IsEmpty() )
    {
        url += "/";
        url += m_repoSubdir;
    }
    
    return url;
}

/**
 * Return the api.github.com URL
 */
wxString GITHUB_URL::GetApiURL() const
{
    wxString url = "https://api.github.com/repos/";
    
    url += m_repoOrg + "/" + m_repoName;
    url += "/contents";
    
    if( !m_repoSubdir.IsEmpty() )
    {
        url += "/";
        url += m_repoSubdir;
    }
    
    return url;
}

/**
 * Return the raw.githubusercontent.com URL
 */
wxString GITHUB_URL::GetRawURL() const
{
    wxString url = "https://raw.githubusercontent.com/";

    url += m_repoOrg + "/" + m_repoName;
    url += "/master";

    if( !m_repoSubdir.IsEmpty() )
    {
        url += "/";
        url += m_repoSubdir;
    }

    return url;
}
