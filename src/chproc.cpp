/*
Copyright (C) 2023 pom@vro.life

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <cerrno>
#include <cstring>
#include <sys/mount.h>

#include <iostream>

int main(int argc, char* argv[])
{
    if (umount("/proc") != 0) {
        std::cout << "Failed to umount old /proc. " << strerror(errno) << std::endl;
        return -1;
    }

    if (mount("none", "/proc", "proc", 0, nullptr) != 0) {
        std::cout << "Failed to mount new /proc. " << strerror(errno) << std::endl;
        return -1;
    }
    return 0;
}
