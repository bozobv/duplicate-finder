#include "../heather/Network.h"

int main() {
    Network network = Network();

    network.readFile();

    network.getDuplicates();
    network.sortDuplicates();

    network.writeFile();

    //network.printDuplicates();

    return 0;
}


