class Codec {
    void serializeHelper(TreeNode *root, ostringstream &ss)
    {
        if(root == nullptr)
        {
            ss << "# ";
            return ;
        }
        ss << root->val << ' ';
        serializeHelper(root->left, ss);
        serializeHelper(root->right, ss);
    }

    TreeNode *deserializeHelper(istringstream &ss)
    {
        string str;
        ss >> str;
        if(str == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(str));
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream ss;
        serializeHelper(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));