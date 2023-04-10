import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val){
        this.val=val;
    }
}
class Q1{
    public static void main(String[] args) {
        TreeNode root=createTree();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter node to find");
        int val=sc.nextInt();
        System.out.println(bfs(val,root));
    }
    public static boolean bfs(int val,TreeNode root){
        boolean flag=false;
        Queue<TreeNode> q=new ArrayDeque<>();
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode curr=q.poll();
            System.out.print(curr.val+" ");
            if(curr.val==val) flag=true;
            if(curr.left!=null) q.offer(curr.left);
            if(curr.right!=null) q.offer(curr.right);
        }
        return flag;

    }
    public static TreeNode createTree(){
        TreeNode root=new TreeNode(1);
        root.left=new TreeNode(2);
        root.right=new TreeNode(3);
        root.left.left=new TreeNode(4);
        root.left.right=new TreeNode(5);
        root.right.right=new TreeNode(6);
        root.left.right.left=new TreeNode(7);
        root.left.right.right=new TreeNode(8);
        root.right.right.left=new TreeNode(9);
        return root;
    }
}