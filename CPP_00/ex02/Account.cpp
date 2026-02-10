#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
    return ;
}

Account::~Account(void)
{
    return ;
}

int	Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
    return (_totalAmount);
}

int	Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
    return ;
}

void	Account::makeDeposit(int deposit)
{
    return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    return ;
}

int		Account::checkAmount(void) const
{
    return ;
}

void	Account::displayStatus(void) const
{
    return ;
}
