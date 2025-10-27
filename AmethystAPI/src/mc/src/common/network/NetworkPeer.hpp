#pragma once

class NetworkPeer {
public:
    enum class Reliability : int {
        Reliable, 

        // the default use for packets
        ReliableOrdered, 

        Unreliable, 
        UnreliableSequenced
    };
};

enum class Compressibility : int {
    Compressible, 
    Incompressible
};