#include<iostream>
#include<vector>
using namespace std;

int main(){
    int size;
    cin >> size; // N: Total number of coin boxes

    // Arrays ko size+2 ka rakhte hain taki '0' based indexing aur last element (size+1) pe safe rahe
    vector<int> f(size+2, 0); // f[i] store karega finally ki i-th box mein kitne coins hain
    vector<int> l(size+2, 0); // l[i] store karega ki kitni baar koi range index 'i' se START hui
    vector<int> r(size+2, 0); // r[i] store karega ki kitni baar koi range index 'i' pe END hui

    int m;
    cin >> m; // M: Number of days (kitni baar coin dalna hai)

    // Har din ke liye L aur R input le rahe hain
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y; // Range [x, y] mili jisme 1 coin daalna hai
        l[x]++;        // Mark karo ki ek range x se shuru ho rahi hai
        r[y]++;        // Mark karo ki ek range y pe khatam ho rahi hai
    }

    // Har box mein final coins calculate karte hain (Difference Array jaisa approach)
    // Formula: Aaj ke box ke coins = (Pichle box ke coins) + (Nayi range jo yaha se shuru hui) - (Jo range pichle wale pe khatam ho gayi)
    for(int i=1; i<=size; i++){  
        f[i] = f[i-1] + l[i] - r[i-1];
    }

    // Ab hume queries ka answer dena hai: "Kitne boxes mein >= X coins hain?"
    // Iske liye hum pehle FREQUENCY nikalenge: "Kitne boxes mein EXACTLY 'C' coins hain?"
    vector<int> freq(size+2, 0);
    for(int i=1; i<=size; i++){
        freq[f[i]]++; // f[i] batata hai 'i' box me kitne coins hain, uski frequency badha do
    }

    // Ab hum SUFFIX SUM nikalenge freq[] ka.
    // suffix_sum[i] = suffix_sum[i+1] + freq[i]
    // Iska matlab hai: (>= i coins wale) = (>= i+1 coins wale) + (exactly i coins wale)
    vector<int> suffix_sum(size+2, 0);
    for(int i=size; i>=1; i--){
        suffix_sum[i] = suffix_sum[i+1] + freq[i];
    }

    int no_of_queries;
    cin >> no_of_queries; // Q: Number of queries
    
    // Har query ka answer do
    for(int i=1; i<=no_of_queries; i++){
       int x;
       cin >> x; // X: Hume bataana hai kitne boxes mein >= X coins hain
       
       // Agar X total boxes (size) se bhi bada hai, toh aisa koi box ho hi nahi sakta
       if(x > size){
           cout << 0 << endl;
       } else {
           cout << suffix_sum[x] << endl; 
       }
    }
    
    return 0;
}