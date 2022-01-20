class Node:
    def __init__(self, infixe, prefixe):
        self.infixe = infixe
        self.prefixe = prefixe
        self.root = None
        self.left = None
        self.right = None
        self.build()
    
    def build(self):
        if len(self.prefixe):
            self.root = self.prefixe[0]
            idx_root = self.infixe.find(self.root)
            left_ifx_nodes = self.infixe[:idx_root]
            right_ifx_nodes = self.infixe[idx_root+1:] 
        
            if len(left_ifx_nodes):
                left_pfx_nodes = ""
                for c in self.prefixe[1:]:
                    if c in left_ifx_nodes:
                        left_pfx_nodes += c
                    else:
                        break
                self.left = Node(left_ifx_nodes, left_pfx_nodes)
        
            if len(right_ifx_nodes):
                right_pfx_nodes = ""
                idx = 0
                for c in self.prefixe:
                    if c not in right_ifx_nodes:
                        idx += 1
                    else:
                        break
                right_pfx_nodes = self.prefixe[idx:]
                self.right = Node(right_ifx_nodes, right_pfx_nodes)
    
    def print(self):
        print(self.root,end='') 


def rec(node):
    if node.left != None:
        rec(node.left)
    if node.right != None:
        rec(node.right)
    node.print()

    

t = int(input())
for T in range(t):
    line = list(input().split())
    n = int(line[0])
    prefixe = line[1]
    infixe = line[2]
    tree = Node(infixe, prefixe)
    rec(tree)
    print()
