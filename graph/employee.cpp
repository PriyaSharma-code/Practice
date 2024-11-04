//690. Employee Importance

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    // Helper function to find the Employee object with the given id
    Employee* helper(vector<Employee*> employees, int id) {
        for (auto e : employees) {
            if (e->id == id) {
                return e;
            }
        }
        return nullptr; // Return nullptr if the employee is not found
    }

    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0; // Initialize the total importance value
        queue<Employee*> q; // Queue for BFS
        q.push(helper(employees, id)); // Start BFS with the given employee id

        while (!q.empty()) {
            Employee* emp = q.front(); // Get the front employee from the queue
            ans += emp->importance; // Add their importance to the total
            q.pop(); // Remove the front employee from the queue

            // Add all subordinates of the current employee to the queue
            for (auto e : emp->subordinates) {
                q.push(helper(employees, e));
            }
        }

        return ans; // Return the total importance value
    }
};
