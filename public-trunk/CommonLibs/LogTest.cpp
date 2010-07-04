/*
* Copyright 2009 Free Software Foundation, Inc.
*
* This software is distributed under the terms of the GNU Public License.
* See the COPYING file in the main directory for details.
*
* This use of this software may be subject to additional restrictions.
* See the LEGAL file in the main directory for details.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <iostream>
#include <iterator>

#include "Logger.h"
#include "Configuration.h"

ConfigurationTable gConfig;
//ConfigurationTable gConfig("example.config");

void printAlarms()
{
    std::ostream_iterator<std::string> output( std::cout, "\n" );
    std::list<std::string> alarms = gGetLoggerAlarms();
    std::cout << "#alarms = " << alarms.size() << std::endl;
    std::copy( alarms.begin(), alarms.end(), output );
}

int main(int argc, char *argv[])
{
	gLogInit("NOTICE");

	LOG(ERROR) << " testing the logger.";
	LOG(WARN) << " testing the logger.";
	LOG(NOTICE) << " testing the logger.";
	LOG(INFO) << " testing the logger.";
	LOG(DEBUG) << " testing the logger.";
	LOG(DEEPDEBUG) << " testing the logger.";
    std::cout << "\n\n\n";
    std::cout << "testing Alarms - you should run apps/showalarms.py to check udp\n";
	LOG(ALARM) << " testing the logger alarm.";
    std::cout << "you should see one line:" << std::endl;
    printAlarms();
    std::cout << "----------- generating 20 alarms ----------" << std::endl;
    for (int i = 0 ; i < 20 ; ++i) {
        LOG(ALARM) << i;
    }
    std::cout << "you should see ten line with the numbers 10..19:" << std::endl;
    printAlarms();
}



