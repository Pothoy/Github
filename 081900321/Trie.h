#include<map>
#include<string> 
using namespace std;

class Tree;
class TreeNode {
	friend class Tree;
	typedef map<string, TreeNode> _TreeMap;
	typedef map<string, TreeNode>::iterator _TreeMapIterator;
private:
	string m_character;
	_TreeMap m_map;
	TreeNode* m_parent;
public:
	TreeNode(string character);
	TreeNode() {
		m_character = "";
	};
	string getCharacter() const;
	TreeNode* findChild(string& nextCharacter);
	TreeNode* insertChild(string& nextCharacter);
};