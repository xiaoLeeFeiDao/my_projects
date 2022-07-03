#ifndef __STONE_ADDRESS_H_
#define __STONE_ADDRESS_H_

#include <memory>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>

namespace stone {

class Address {
public:
typedef std::shared_ptr<Address> ptr;
Virtual ~Address();
    }
}

#endif