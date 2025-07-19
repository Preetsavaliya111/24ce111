#include <iostream>
#include <windows.h>     // For Sleep()
#include <cstdlib>       // For rand(), srand()
#include <ctime>         // For time()
#include <cmath>         // For fabs()
#include <iomanip>       // For setprecision()
#include<chrono>
using namespace std;

int main()
 {
    srand(time(0));
    int target = (rand() % 20) + 1;
    cout << "Target time (seconds): " << target << endl;

    Sleep(3000); // Pause before hiding target (3 seconds)
    system("cls"); // Clears console screen (Windows only)

    // === Player 1 ===
    cout << "Player 1: Press ENTER when you think " << target << " seconds have passed..." << endl;
    auto start1 = chrono::steady_clock::now();
    cin.ignore();
    auto end1 = chrono::steady_clock::now();
    double time1 = chrono::duration<double>(end1 - start1).count();

    // === Player 2 ===
    cout << "Player 2: Press ENTER when you think " << target << " seconds have passed..." << endl;
    auto start2 = chrono::steady_clock::now();
    cin.ignore();
    auto end2 = chrono::steady_clock::now();
    double time2 = chrono::duration<double>(end2 - start2).count();

    // === Results ===
    double diff1 = fabs(time1 - target);
    double diff2 = fabs(time2 - target);

    cout << fixed << setprecision(2);
    cout << "\nResults:\n";
    cout << "Player 1 stopped at: " << time1 << " seconds (diff: " << diff1 << ")\n";
    cout << "Player 2 stopped at: " << time2 << " seconds (diff: " << diff2 << ")\n";

    if (diff1 < diff2) cout << "🏆 Player 1 wins!\n";
    else if (diff2 < diff1) cout << "🏆 Player 2 wins!\n";
    else cout << "🤝 It's a tie!\n";

    return 0;
}