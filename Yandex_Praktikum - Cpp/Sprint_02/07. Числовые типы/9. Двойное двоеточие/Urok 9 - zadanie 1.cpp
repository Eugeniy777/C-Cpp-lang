#include <iostream>

using namespace std;

/*
enum class DocumentStatus {
    ACTUAL,
    IRRELEVANT,
    BANNED,
    REMOVED,
};
*/

class SearchServer {
public:
    enum class DocumentStatus {
    ACTUAL,
    IRRELEVANT,
    BANNED,
    REMOVED,
};
};

int main() {
    cout << static_cast<int>(SearchServer::DocumentStatus::BANNED) << endl;
    return 0;
}




/*
Задание 1


Научитесь работать с перечислимым типом, объявленным внутри класса. Для этого перенесите объявление DocumentStatus в публичную секцию класса SearchServer, а в функции main выведите численное значение статуса BANNED.
*/




/*
// Решение от авторов:


#include <iostream>
 
using namespace std;
 
class SearchServer {
public:
    enum class DocumentStatus {
        ACTUAL,
        IRRELEVANT,
        BANNED,
        REMOVED,
    };
};
 
int main() {
    cout << static_cast<int>(SearchServer::DocumentStatus::BANNED) << endl;
    return 0;
}
*/