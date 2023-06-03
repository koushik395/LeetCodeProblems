class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        for(auto& email:emails){
            auto at_location = find(email.begin(),email.end(),'@');
            auto end_after_removing_dots = remove(email.begin(),at_location,'.');
			auto plus_location = find(email.begin(),end_after_removing_dots,'+');
            email.erase(plus_location,at_location);
        }
        return unordered_set(emails.begin(),emails.end()).size();
    }
};