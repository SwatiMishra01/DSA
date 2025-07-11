https://www.naukri.com/code360/problems/maximum-meetings_1062658

int maximumMeetings(vector<int> &start, vector<int> &end)
{ 
    //meetings array as-> {(end,start)....}
    vector<pair<int,int>>meetings;
    for(int i=0; i<start.size(); i++){
        meetings.push_back({end[i],start[i]});
    }
    //sort according to end times
    sort(meetings.begin(),meetings.end());
    int cnt=1;
    //end time of meeting 1
    int freeTime=meetings[0].first;
    for(int i=1; i<meetings.size(); i++){
        //if meeting start after free times then count++
        if(meetings[i].second>freeTime){
        cnt++;
        //update free time
        freeTime=meetings[i].first;
        }
    }
    return cnt;
}

T.C=O(N)
S.C=O(N)
