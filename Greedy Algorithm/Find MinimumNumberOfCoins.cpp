vector<int> MinimumCoins(int amount)
{
    // Write your code here

    vector<int> coins={1000,500,100,50,20,10,5,2,1};
    vector<int> res;

    for(int i=0; i<=8; i++)
    {
        while(amount>=coins[i])
        {
            amount-=coins[i];
            res.push_back(coins[i]);
        }
    }
    return res;
}
