#include "MyEngine.h"

void MyEngine::show()
{
    if (p_view) {
        p_view->show();
    }
}
