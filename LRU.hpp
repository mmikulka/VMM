//
//  LRU.hpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#ifndef LRU_hpp
#define LRU_hpp

#include <stdio.h>
#include "PRA.hpp"
#include "list"

class LRU : public PRA {
public:
    LRU();
    unsigned select_frame(int);
    void update_usage(uint32_t);
    ~LRU();

private:
  list <LRU_Status> used_list;

  struct LRU_Status
  {
  public:
    int time;
    uint32_t frameNum;

  }

};

#endif /* LRU_hpp */
