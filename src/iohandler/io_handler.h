/*MT*

    MediaTomb - http://www.mediatomb.cc/

    io_handler.h - this file is part of MediaTomb.

    Copyright (C) 2005 Gena Batyan <bgeradz@mediatomb.cc>,
                       Sergey 'Jin' Bostandzhyan <jin@mediatomb.cc>

    Copyright (C) 2006-2010 Gena Batyan <bgeradz@mediatomb.cc>,
                            Sergey 'Jin' Bostandzhyan <jin@mediatomb.cc>,
                            Leonhard Wimmer <leo@mediatomb.cc>

    Copyright (C) 2016-2025 Gerbera Contributors

    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2
    as published by the Free Software Foundation.

    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    version 2 along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.

    $Id$
*/

/// \file io_handler.h
/// \brief Definition for the IOHandler class.

#ifndef __IO_HANDLER_H__
#define __IO_HANDLER_H__

#include <cstddef>
#include <cstdint>
#include <upnp.h>

using grb_read_t = std::int32_t;
static constexpr grb_read_t CHECK_SOCKET = -666;

class IOHandler {
public:
    virtual ~IOHandler() = default;

    /// \brief Opens a data for the web server.
    /// \param mode in which the data will be opened (we only support UPNP_READ)
    virtual void open(enum UpnpOpenFileMode mode);

    /// \brief Reads previously opened/initialized data sequentially.
    /// \param buf This buffer will be filled by our read functions.
    /// \param length Number of bytes to read.
    virtual grb_read_t read(std::byte* buf, std::size_t length);

    /// \brief Writes to previously opened/initialized data sequentially.
    /// \param buf Data to be written.
    /// \param length Number of bytes to write.
    virtual std::size_t write(std::byte* buf, std::size_t length);

    /// \brief Performs a seek on an open/initialized data.
    /// \param offset Number of bytes to move in the buffer.

    /// For seeking forwards
    /// positive values are used, for seeking backwards - negative. \b Offset must
    /// be positive if \b origin is set to \b SEEK_SET
    /// \param whence The position to move relative to. SEEK_CUR to move relative
    /// to current position, SEEK_END to move relative to the end of file,
    /// SEEK_SET to specify an absolute offset.
    virtual void seek(off_t offset, int whence);

    /// \brief Return the current stream position.
    virtual off_t tell();

    /// \brief Close/free previously opened/initialized data.
    virtual void close();
};

#endif // __IO_HANDLER_H__
