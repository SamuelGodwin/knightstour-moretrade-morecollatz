#include "collatz.h"

#include <vector>
using std::vector;

#include <cmath>

#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::pair;

int main() {
    
    {
        auto ans = collatz(6);
        if (ans == 9) {
            cout << "Does collatz(6) return 9?  Yes\n";
        } else {
            cout << "Does collatz(6) return 9?  No, it returns " << ans << "\n";        
        }
    }
    {
        auto ans = collatz(9);
        if (ans == 20) {
            cout << "Does collatz(9) return 20?  Yes\n";
        } else {
            cout << "Does collatz(9) return 20?  No, it returns " << ans << "\n";        
        }
    }
    
    vector<int> bounds{10,100,1000,10000,100000,1000000};
    vector<pair<uint64_t, uint64_t> > answers{
        {20, 9     },
        {119,97    },
        {179,871   },
        {262,6171  },
        {351,77031 },
        {525,837799}
    };
    
    for (size_t i = 0; i < bounds.size(); ++i) {
        cout << "Running collatz_max(" << bounds[i] << "): ";
        cout.flush();
        
        auto ans = collatz_max(bounds[i]);
        if (ans == answers[i]) {
            cout << "passed, returns correct answer of ";
        } else {
            cout << "failed, returns {" << ans.first << ", " << ans.second << "} rather than correct answer of ";
        }
        cout << "{" << answers[i].first << ", " << answers[i].second << "}\n";
    }

}
