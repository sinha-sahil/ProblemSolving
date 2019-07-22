//
// Created by Sahil_Sinha on 2019-07-10.
//

#ifndef CLIONPROJECTS_UTILS_H
#define CLIONPROJECTS_UTILS_H

#endif //CLIONPROJECTS_UTILS_H

#include <iostream>
#include <vector>
#pragma once

class vectorInput{
    public:
    std::vector<int> vectorInp(){
        int s;
        std::cin>>s;
        std::vector<int> vi(s);
        for(int i=0; i<s; i++) std::cin>>vi[i];
        return vi;
    }
};