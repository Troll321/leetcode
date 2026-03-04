typedef long long ll;
const ll MAXN = 1e5 + 5;

class State {
public:
    static vector<State*> asli, tambahan;
    
    ll idx = -1;
    char now = '\0';
    char nxt = '\0';
    bool isRepeating = false;
    bool verdict = true;
    string str = "";

    State(string str) {
        this->str = str;
        next();
    }

    State(State* toCopy) {
        this->idx = toCopy->idx;
        this->now = toCopy->now;
        this->nxt = toCopy->nxt;
        this->isRepeating = toCopy->isRepeating;
        this->verdict = toCopy->verdict;
        this->str = toCopy->str;
    }

    void next(bool isTambahan = false) {
        char tmp = now;
        idx = min(idx+1ll, (ll)str.size());
        if(idx == str.size()) {
            now = isRepeating ? now : '\0';
        } else {
            now = str[idx];
        }

        if(now == '*') {
            isRepeating = true;
            now = tmp;
        } else {isRepeating = false;}

        if(idx+1 >= str.size()) {
            nxt = '\0';
        } else {
            nxt = str[idx+1];
        }

        if(nxt == '*') {
            next(isTambahan);
            return ;
        }

        if(isRepeating) {
            if(isTambahan) {
                State::tambahan.push_back(new State(this));
            } else {
                State::asli.push_back(new State(this));
            }
            isRepeating = false;
            next(isTambahan);
        }
    }

    void match(char c) {
        if(!verdict) {return ;}
        if (now != c && now != '.') {
            if(idx == str.size()) {verdict = false; return ;}
            if (isRepeating) {
                isRepeating = false;
                next();
                match(c);
                return ;
            } else {
                verdict = false;
                return ;
            }
        }

        if(isRepeating) {
            // Mau next atau engga
            State::tambahan.push_back(new State(this));
        }
        next(true);
    }

    bool getVerdict(char c) {
        if(!verdict) {return false;}
        return idx == str.size();
        // cout << idx << " " << isRepeating << "!\n";
        // char bef = !isRepeating ? (idx > 0 ? str[idx-1] : '*') : (idx > 1 ? str[idx-2] : '*');
        // bool awal = isRepeating && bef == '*';
        // while(verdict && idx != str.size()) {
        //     if(isRepeating) {
        //         next(true);
        //     } else {
        //         if(awal) {
        //             match(c);
        //             awal = false;
        //             continue ;
        //         }
        //         return false;
        //     }    
        // }
        // return verdict;
    }
};

vector<State*> State::asli, State::tambahan;

void gmatch(char c) {
    ll tambahan = State::tambahan.size();
    for(int i = 0; i < tambahan; i++ ) {
        State::tambahan[i]->match(c);
    }
    for(int i = 0; i < State::asli.size(); i++ ) {
        State::asli[i]->match(c);
    }

    if(State::asli.size() > 50000) {
        ll len = (State::asli.size()/3*2);
        State::asli.erase(State::asli.begin(), State::asli.begin() + len);
    }
    if(State::tambahan.size() > 50000) {
        ll len = (State::tambahan.size()/3*2);
        State::tambahan.erase(State::tambahan.begin(), State::tambahan.begin() + len);
    }
}

bool gverdict(char c) {
    ll tambahan = State::tambahan.size();
    for(int i = 0; i < tambahan; i++ ) {
        if (State::tambahan[i]->getVerdict(c)) {return true;}
    }
    for(int i = 0; i < State::asli.size(); i++ ) {
        if (State::asli[i]->getVerdict(c)) {return true;}
    }
    return false;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        State::asli.clear();
        State::tambahan.clear();
        State::asli.push_back(new State(p));
        for(char c : s) {gmatch(c);}
        return gverdict(s.back());
    }
};