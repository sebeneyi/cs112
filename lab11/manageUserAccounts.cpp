/* manageUserAccounts.cpp contains the "driver" for class AccountManager.
 * Joel Adams, for CS 112 at Calvin College.
 *
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (lab 11)
 * Date: May 06, 2019
 */

#include "AccountManager.h"

int main() {
	AccountManager manager("accountInfo.txt");
	manager.run();
}
