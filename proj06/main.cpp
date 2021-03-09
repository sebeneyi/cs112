/* main.cpp is the driver for a Conga line simulation.
 * @author: Joel Adams, for CS 112 at Calvin College.
 * Based on an exercise by Marc LeBlanc from Wheaton College (MS).
 *
 * Student: Sebene Yi (ssy3), for CS 112 at Calvin College
 * Date: March 12, 2019
 */
#include "CongaLine.h"
#include "List.h"
#include "ListTester.h"

int main() {
	ListTester lt;
	lt.runTests();
	CongaLine dance("Ann", "Bob");
	dance.run();

}
