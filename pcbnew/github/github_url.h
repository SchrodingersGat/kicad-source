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
 
#ifndef GITHUB_URL_H_
#define GITHUB_URL_H_
 
#include <wx/string.h>

/**
 * Class GITHUB_URL
 * provides simple management of a GitHub URL
 */
class GITHUB_URL
{
public:
    GITHUB_URL() {}
    GITHUB_URL( const wxString& aUrl );

    bool IsValid() const;
    bool SetUrl( const wxString& aUrl );

    wxString GetRepoOrg() const { return m_repoOrg; }
    wxString GetRepoName() const { return m_repoName; }
    wxString GetRepoSubdir() const { return m_repoSubdir; }

    wxString GetFullURL( bool aIncludeTree = false ) const;
    wxString GetApiURL() const;
    wxString GetRawURL() const;

protected:
    wxString m_repoOrg;     // Organization name e.g. 'KiCad'
    wxString m_repoName;    // Repo name e.g. 'kicad-library'
    wxString m_repoSubdir;  // Subdir name e.g. '/modules/packages3d' (optional)
};
 
#endif // GITHUB_URL_H_
