#include  "Adapter Pattern/Socket.h"
#include "Adapter Pattern/Adapter.h"
#include "Adapter Pattern/Blender.h"


using namespace std;
int main() {
    Socket* socket = new Socket;
    Adapter* adapter = new Adapter;
    Blender* blender = new Blender;

    /* Pluging in. */
    adapter->plugIn(socket);
    blender->plugIn(adapter);

    /* Having coffee */
    blender->liquefy();

    return 0;
}
