// Problem - 468

// https://leetcode.com/problems/validate-ip-address/

// O(n) time complexity and O(1) space complexity solution usign regex

class Solution {
public:
    
    string validIPAddress(string IP) {
         regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
        if(regex_match(IP, ipv4)) 
            return "IPv4";
        else if(regex_match(IP, ipv6))
            return "IPv6";
        return "Neither";
    }
};
