class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def flipEquiv(root1: TreeNode, root2: TreeNode) -> bool:

    if not root1 and not root2:
        return True
    
    if not root1 or not root2:
        return False
    
    if root1.val != root2.val:
        return False
    
    # 1. Trees are identical without any flip
    # 2. Trees become identical after flipping left and right subtrees
    return (flipEquiv(root1.left, root2.left) and flipEquiv(root1.right, root2.right)) or \
           (flipEquiv(root1.left, root2.right) and flipEquiv(root1.right, root2.left))

# Example:
root1 = TreeNode(1)
root1.left = TreeNode(2)
root1.right = TreeNode(3)
root1.left.left = TreeNode(4)
root1.left.right = TreeNode(5)
root1.right.left = TreeNode(6)
root1.left.right.left = TreeNode(7)
root1.left.right.right = TreeNode(8)

root2 = TreeNode(1)
root2.left = TreeNode(3)
root2.right = TreeNode(2)
root2.left.right = TreeNode(6)
root2.right.left = TreeNode(4)
root2.right.right = TreeNode(5)
root2.right.right.left = TreeNode(8)
root2.right.right.right = TreeNode(7)

# Check if the two trees are flip equivalent
result = flipEquiv(root1, root2)
print("Flip Equivalent:", result)  
