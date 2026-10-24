class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> predays = {0,   31,  59,  90,  120, 151,
                               181, 212, 243, 273, 304, 334};

        int arrA = predays[stoi(arriveAlice.substr(0, 2)) - 1] +
                   stoi(arriveAlice.substr(3, 2));
        int leaveA = predays[stoi(leaveAlice.substr(0, 2)) - 1] +
                     stoi(leaveAlice.substr(3, 2));
        int arrB = predays[stoi(arriveBob.substr(0, 2)) - 1] +
                   stoi(arriveBob.substr(3, 2));
        int leaveB = predays[stoi(leaveBob.substr(0, 2)) - 1] +
                     stoi(leaveBob.substr(3, 2));

        if (leaveA < arrB || leaveB < arrA)
            return 0;

        return min(leaveA, leaveB) - max(arrA, arrB) + 1;
    }
};