#include <bits/stdc++.h>
using namespace std;

class Contributor {
public:
    string name;
    vector<pair<string,int>> skills;
//init
    Contributor(string name, vector<pair<string,int>> skills) {
        this->name = name;
        this->skills = skills;
    }
};

class Projects {
public:
    string name;
    int days;
    int point;
    int bestbefore;
    int no_contributors;
    vector<Contributor> contributors;
    vector<pair<string,int>> skills_project;
//init
    Projects(string name, int days, int point, int bestbefore, int no_contributors, vector<pair<string,int>> skills_project) {
        this->name = name;
        this->days = days;
        this->point = point;
        this->bestbefore = bestbefore;
        this->no_contributors = no_contributors;
        this->skills_project = skills_project;
        this->contributors = vector<Contributor>(no_contributors);
    }
};

bool isProjectDoable(Projects project , vector<Contributor> contributors){
    vector<pair<string,int>> ::iterator itr;
    for(int i=0;i<project.skills_project.size();i++){
        itr = find(contributors[i].skills.begin(),contributors[i].skills.end(),project.skills_project[i]);
        if(itr == contributors[i].skills.end()){
            return false;
        }
        else if (itr->second < project.skills_project[i].second && !isMentorAvailable(project, project.skills_project[i].first,project.skills_project[i].second) ){
            return false;
        }
        else if (itr->second <project.skills_project[i].second-1 && isMentorAvailable(project, project.skills_project[i].first,project.skills_project[i].second)){
            return false;
        }
    }
    return true;

}

bool isMentorAvailable(Projects project, string skill_required , int skill_level){
    vector<Contributor> contributors = project.contributors;
    if(contributors.size() == 0 || (contributors.size()==1 && contributors[0].skills.size()==1)){
        return false;
    }
    vector<pair<string,int>> ::iterator itr;
    for(int i=0;i<contributors.size();i++){
        itr = find(contributors[i].skills.begin(),contributors[i].skills.end(),skill_required);
        if(itr == contributors[i].skills.end()){
            return false;
        }
        else if (itr->second < skill_level){
            return false;
        }
    }
    return true;
}

int main(){
    int num_contributors;
    int num_projects;
    cin >> num_contributors >> num_projects;
    vector<Contributor> contributors(num_contributors);
    while(num_contributors--){
        string name;
        int num_skills;
        cin >> name >> num_skills;
        vector<pair<string,int>> skills(num_skills);
        for(int i=0;i<num_skills;i++){
            string skill;
            int level;
            cin >> skill >> level;
            skills[i] = make_pair(skill,level);
        }
        contributors[num_contributors] = Contributor(name,skills);
    }
    vector<Projects> projects(num_projects);
    while(num_projects--){
        string name;
        int days;
        int point;
        int bestbefore;
        int no_contributors;
        int num_skills;
        cin >> name >> days >> point >> bestbefore >> no_contributors >> num_skills;
        vector<pair<string,int>> skills(num_skills);
        for(int i=0;i<num_skills;i++){
            string skill;
            int level;
            cin >> skill >> level;
            skills[i] = make_pair(skill,level);
        }
        projects[num_projects] = Projects(name,days,point,bestbefore,no_contributors,skills);
    }
    //sorts the projects by bestbefore/points
    sort(projects.begin(),projects.end(),[](Projects a, Projects b){
        return a.bestbefore/a.point < b.bestbefore/a.point;
    });
    int i=0;
    while(!projects.empty()){
        if(isProjectDoable(projects[i],contributors)){
            projects.erase(projects.begin()+i);
            incrementContributorSkills(projects[i]);
            //points increase
            i=0;
            
        }
        else{
            i++;
        }
    }
}

void incrementContributorSkills(Projects project){
   vector <Contributor> contributors = project.contributors;

}

