#include <iostream>
#include <string>
#include <cstring>
int main(int argc, const char *argv[]) {
    const char *Main = "annbcdanacadsannannacanna";
    const char *Pattern = "annacanna";
    int mL = strlen(Main);
    int pL = strlen(Pattern);
    int next[pL];
    next[0] = 0;
    next[1] = 0;
    int i = 1, j = 0;
    while (i < pL - 1) {
        if (Pattern[i] == Pattern[j]) {
            next[++i] = ++j;
        } else if (j == 0) {
            next[++i] = 0;
        } else {
            j = next[j];
        }
    }
    i = j = 0;
    while (i < mL) {
        // std::cout << std::string(i * 2, ' ') << 'i' << std::endl;
        // for (int k = 0; k < mL; ++k) {
        //     std::cout << Main[k] << ' ';
        // }
        // std::cout << std::endl << std::string(i * 2, ' ');
        // for (int k = 0; k < pL; ++k) {
        //     std::cout << Pattern[k] << ' ';
        // }
        // std::cout << std::endl << std::string(i * 2, ' ');
        // for (int k = 0; k < pL; ++k) {
        //     std::cout << next[k] << ' ';
        // }
        // std::cout << std::endl;
        // std::cout << std::string(i * 2 + j * 2, ' ') << 'j' << std::endl << std::endl;
        if (Main[i] == Pattern[j]) {
            ++i;
            if (++j == pL) {
                i -= pL;
                break;
            }
        } else if (j == 0) {
            ++i;
        } else {
            j = next[j];
        }
    }
    if (j == pL) {
        std::cout << "Position: " << i << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }
}
