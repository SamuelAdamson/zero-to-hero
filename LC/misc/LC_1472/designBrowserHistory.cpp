class BrowserHistory {
private:
    vector<string> history;
    int currPage, maxPage;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currPage = 0, maxPage = 0;
    }
    
    void visit(string url) {
        if(currPage == history.size()-1) {
            history.push_back(url);
            maxPage = ++currPage;
        }
        else {
            history[++currPage] = url;
            maxPage = currPage;
        }
    }
    
    string back(int steps) {
        if(steps > currPage) currPage = 0;
        else currPage -= steps;
        return history[currPage];
    }
    
    string forward(int steps) {
        if(currPage + steps > maxPage) currPage = maxPage;
        else currPage += steps;
        return history[currPage];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */