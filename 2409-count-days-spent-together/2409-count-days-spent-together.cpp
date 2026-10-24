vector<int> days;
class Solution {
public:
    void generate(){
        static bool done = false;
        if(done) return;
        done = false;
        days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        return;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        generate();
        int a = days[(arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0') -1] + ((arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0'));
        int b = days[(leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0') -1] + ((leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0'));
        int c = days[(arriveBob[0]-'0')*10 + (arriveBob[1]-'0') -1] + ((arriveBob[3]-'0')*10 + (arriveBob[4]-'0'));
        int d = days[(leaveBob[0]-'0')*10 + (leaveBob[1]-'0') -1] + ((leaveBob[3]-'0')*10 + (leaveBob[4]-'0'));
        return max(min(b,d)-max(a,c)+1,0);
    }
};