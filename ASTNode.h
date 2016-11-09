enum ASTNodeType 
{
   /*List all possible type of parents and children. basically nonterminals and terminals*/
};
 
class ASTNode
{
public:
   ASTNodeType Type;
   auto      Value;
   ASTNode*    Left;
   ASTNode*    Right;
 
   ASTNode()
   {
      Type = Undefined;
      Value = 0;
      Left = NULL;
      Right = NULL;
   }
 
   ~ASTNode()
   {
      delete Left;
      delete Right;
   }
};
