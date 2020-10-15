//
// Created by psifunction on 13.10.2020.
//

#ifndef ANIMATION_LINE_H
#define ANIMATION_LINE_H

extern const int meter;

#include <vector>

class Line {
public:
    Line() {

        for (int i = 0; i < lengths.size(); ++i) {
            float offset = 0.f;
            for (int j = 0; j < i; ++j) {
                offset += lengths[j];
            }
           coords.push_back(8*(i+1) + offset * meter);
        }
    }

    Line(const Line&) = delete;
    Line(Line&&) = delete;
    Line operator=(const Line&) = delete;
    Line operator=(Line&&) = delete;


    float getLogSpeed(int x){
        for (int i = coords.size()-1; i >= 0; --i){
            if (x >= coords.at(i)){
                return speeds.at(i);
            }
        }
        return 30.f;

    }

    int getElemCount(){
        return lengths.size();
    }

    std::vector<float> coords;

    const std::vector<float> lengths = {6.5f, 8.f, 6.75f, 6.75f, 4.5f, 4.5f};
    const std::vector<std::string> names = { "buffer","debarker", "scan_in", "scan_out", "end saw", "saw"};
    std::vector<float> speeds = {30.f, 30.f, 30.f, 30.f, 30.f, 30.f};

};


#endif //ANIMATION_LINE_H
