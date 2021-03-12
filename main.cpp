#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct nodes
{
    int data;
    struct nodes *left;
    struct nodes *right;
};

struct nodes *newnodes(int index)
{
    struct nodes *temps =  (struct nodes *) malloc(sizeof(struct nodes));

    temps->data = index;
    temps->left = temps->right = NULL;

    return temps;
}

void pre_order(struct nodes *root)
{
    if (root != NULL)
    {
        pre_order(root->left);
        printf("%d \n", root->data);
        pre_order(root->right);
    }

}

struct nodes* insert(struct nodes* nodes, int data)
{
    if (nodes == NULL)
    {
        return newnodes(data);
    }

    if (data < nodes->data)
    {
        nodes->left  = insert(nodes->left, data);
    }
    else if (data > nodes->data)
    {
      nodes->right = insert(nodes->right, data);
    }

    return nodes;
}

int main()
{

    struct nodes *root = NULL;
	int input_data;

    ifstream input ,output;
	string filename;


	cout << "Enter the file name: ";
    cin >> filename;

	input.open(filename, ios::in);
	output.open(filename,ios::in);

    cout<<endl;

    if(output.good())
    {
        cout<<"Before operation:"<<endl;
        while(!output.eof())
        {
            output>>input_data;
            cout<<input_data<<endl;

        }
    }

   cout <<endl;


	if (input.good())
	{
	    cout<<"After operation:"<<endl;
		while (input >> input_data)
		{
          root = insert(root,input_data);
			insert(root, input_data);
			insert(root, input_data);
			insert(root, input_data);
			insert(root, input_data);
			insert(root, input_data);
            insert(root, input_data);
			insert(root, input_data);
		}

		pre_order(root);
	}

	else

    {
		cout << "The file does not exist." << endl;
	}

}
