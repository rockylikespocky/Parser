enum ASTNodeType 
{
   Undefined,
   OperatorPlus,
   OperatorMinus,
   OperatorMul,
   OperatorDiv,
   UnaryMinus,
   NumberValue
};
 
class ASTNode
{
public:
   ASTNodeType Type;
   double      Value;
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
