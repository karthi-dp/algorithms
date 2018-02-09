/* Problem: verticalOrderTraversal
 * Author: Kartheek Diwakar Pingali
 */



vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    
    
    vector<vector<int> >ans;
    if(!A)
    {
        return ans;
    }
    
    map<int, vector<int> >m;
    queue<pair<TreeNode*, int> >q;
    
    TreeNode* node = A;
    int hd = 0;
    
    q.push(make_pair(node, hd));
    
    while(!q.empty())
    {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        
        hd = temp.second;
        node = temp.first;
        
        m[hd].push_back(node->val);
        
        if(node->left != NULL)
        q.push(make_pair(node->left,hd-1));
        if(node->right != NULL)
        q.push(make_pair(node->right,hd+1));
    }
    
    
    
    map<int, vector<int> >::iterator it;
    
    for(it=m.begin(); it!=m.end();it++)
    {
        vector<int >temp;
        for(int i=0; i< it->second.size(); i++)
        {
            temp.push_back(it->second[i]);
        }
        ans.push_back(temp);
        temp.clear();
    }
    
    return ans;

}
