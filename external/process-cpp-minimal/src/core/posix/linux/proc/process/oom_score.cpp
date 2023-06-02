/*
 * Copyright © 2013 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voß <thomas.voss@canonical.com>
 */

#include <core/posix/linux/proc/process/oom_score.h>

#include <core/posix/process.h>

#include <fstream>
#include <sstream>

namespace core
{
namespace posix
{
namespace Linux
{
namespace proc
{
namespace process
{
const posix::Process& operator>>(const posix::Process& process, OomScore& score)
{
    std::stringstream ss; ss << "/proc/" << process.pid() << "/oom_score";
    std::ifstream in(ss.str());

    in >> score.value;

    return process;
}
}
}
}
}
}
