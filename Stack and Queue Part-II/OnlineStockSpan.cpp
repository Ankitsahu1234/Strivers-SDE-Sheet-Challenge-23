class StockSpanner {
    vector<int> temp;

public:
    StockSpanner() {
        temp.clear();
    }
    
    int next(int price) {
        temp.push_back(price);
        int n=temp.size();
        int count=1;
        for(int i=n-2; i>=0; i--)
        {
            if(temp[i]<=price)
                count++;
            else    
                break;
        }
        return count;
    }
};
