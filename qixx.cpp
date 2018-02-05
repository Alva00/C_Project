#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector> 
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;
/*
 * magic_spell:
 */
struct MS
{
    string magic_spell;  
    int magic_value;    
    int magic_len;		
};

/*
 * Route of the best value
 */
struct Route
{
	string route;
	int pos;
};

/*
 * Tree node
 */
struct Node
{
	int sum; 
	string remain_string;	
	vector<struct Route> route;				
};

/*
 * global variable: save the best answer
 */ 
vector<struct Route> best_route;
int best_sum = 0;

/* 
 * sort the struct
 */
bool cmpValue(MS a, MS b)
{
	return a.magic_value > b.magic_value;
}
/*    
 *	find the substring
 */ 
bool selfFindChar(const char* str, char target, int lenStr)
{
    for(int i=0; i<lenStr; i++)
    {
        if (str[i]==target)
        {
            return true;
        }
    }
    return false;
}
void stringMatching(int magic_spell_num, Node* tree, MS magic_spell[])
{
	if(tree->remain_string.length() == 0 )
	{
		if(tree->sum > best_sum)
		{
			best_route = tree->route;
			best_sum = tree->sum;
		}
		return ;
	}

	bool visit_flag = false;
	vector<string> prune;
    for(int i = 0; i  < magic_spell_num; i++)
    {
    	/* special test handle */
    	if((magic_spell[i].magic_spell.length() == tree->remain_string.length() && magic_spell[i].magic_spell[0] != tree->remain_string[0]) || magic_spell[i].magic_spell.length() > tree->remain_string.length())
    	{
    		continue;
    	}

    	int head = 0; 	
	    for(int j = 0; head <= tree->remain_string.length() - 1;) 
	    {
	        if(tree->remain_string[head + j] == magic_spell[i].magic_spell[j])
	        { 
	            j++;	
	            if(j == magic_spell[i].magic_len) 
	            {
	            	/* add judge */
	            	
	            	Node tmp2;
	            	Node* tmp = &tmp2;
					if(head)
					{
						tmp->remain_string = tree->remain_string.substr(0, head) + tree->remain_string.substr(head+j, tree->remain_string.length()-1);
					}	
	            	else 
	            	{
	            		tmp->remain_string = tree->remain_string.substr(head+j, tree->remain_string.length()-1);
					}
					tmp->sum = tree->sum + magic_spell[i].magic_value;
					Route r_tmp;
					r_tmp.pos = head;
					r_tmp.route = magic_spell[i].magic_spell;
					tree->route.push_back(r_tmp);
					tmp->route = tree->route;
					prune.push_back(magic_spell[i].magic_spell);
					stringMatching(magic_spell_num, tmp, magic_spell);
	            	tree->route.pop_back();
	            	visit_flag = true;
	            } 
	        }        
	        else  
	        {
				if ( selfFindChar(magic_spell[i].magic_spell.c_str(), tree->remain_string[head+magic_spell[i].magic_len], magic_spell[i].magic_len)==true )
                {
					head = head + 1; 
				}
	            else
				{
					head = head + magic_spell[i].magic_len + 1; 
				}
	            j = 0; 
	        }         
	    }
	}

	if(!visit_flag)
	{
		if(tree->sum > best_sum)
		{
			best_route = tree->route;
			best_sum = tree->sum;
		}
		return ;
	}
}


int main(int argc, char* argv[])
{
	/* open the file */
	ifstream filein;
	filein.open(argv[1]);
	if(!filein)
	 { 
	    cerr << "Can't open the file." << endl; 
	    return -1; 
	} 

	/* define and read in variables */
    int string_len;      
    int magic_spell_num;  	
    string magic_book;   	 
	filein >> string_len >> magic_spell_num;
	filein >> magic_book;

    MS magic_spell[magic_spell_num];    
    int magic_spell_count = 0; 
    while(magic_spell_count < magic_spell_num)
    {
        filein >> magic_spell[magic_spell_count].magic_spell >> magic_spell[magic_spell_count].magic_value;
        magic_spell[magic_spell_count].magic_len =  magic_spell[magic_spell_count].magic_spell.length();
        magic_spell_count++;
    }

    /* close file */ 
    filein.close();

    /* build a tree */
    Node* root = new Node();
    root->remain_string = magic_book;
    root->sum = 0;
	stringMatching(magic_spell_num, root, magic_spell);

	/* write file */
	ofstream fileout(argv[2]); 
	for(int i = 0; i < best_route.size(); i++)
	{
		fileout << best_route[i].pos << " " << best_route[i].route << endl;
	}
	fileout << best_sum << endl;

    return 0;
}
