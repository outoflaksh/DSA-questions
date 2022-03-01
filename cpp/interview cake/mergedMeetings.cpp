// given a vector/array of meeting ranges (as represented by 30-min blocks after 9:00am => [2, 3] : 10:00-10:30am),
// return a vector/array of the merged meeting ranges.
// example: [1, 2], [2, 3], [4, 6] becomes [1, 3], [4, 6]
// meeting ranges are represented as Meeting object & input vector is not sorted 

#include <iostream>
#include <vector>

using namespace std;

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};

bool compareStartTimes(Meeting& m1, Meeting& m2) {
    return m1.getStartTime() < m2.getStartTime();
}

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
    // merge meeting ranges
    vector<Meeting> sortedMeetings(meetings);
    sort(sortedMeetings.begin(), sortedMeetings.end(), compareStartTimes);
     
    vector<Meeting> mergedMeetings;
    
    mergedMeetings.push_back(sortedMeetings.front());
    
    for (Meeting& curr : sortedMeetings) {
        Meeting& prevInserted = mergedMeetings.back();
        
        if (prevInserted.getEndTime() >= curr.getStartTime()) {
            prevInserted.setEndTime(max(prevInserted.getEndTime(), curr.getEndTime()));
        } else {
            mergedMeetings.push_back(curr);
        }
    }
    
    
    return mergedMeetings;
}
