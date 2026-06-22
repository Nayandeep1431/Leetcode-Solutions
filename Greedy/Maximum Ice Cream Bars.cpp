int maxIceCream(vector<int>& costs, int coins) {
    int n = costs.size() ;
    sort(costs.begin(), costs.end());

    int cnt = 0;
    for (int cost : costs) {
    if (coins < cost)
        break;
    coins -= cost;
    cnt++;
}
    return cnt;
    }
};
