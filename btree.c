#include <stdio.h>
#include <stdlib.h>
typedef struct {

	struct node* left_child ;
	struct node* right_child ;
	int value ;

} node ;

/* prints the tree level by level */
/*             a
			b     c
*         d   e  f  g
*
*
*  the output is :
*              a
*            b   c
*          d e  f  g 
*
*/
void print_level_tree( node* root ) {
	/* use queues : 
		pop node from queue
		put node's children's in a list
		print nodes'
	*/

}

void print_ancestors( node* root ) {



}

void bfs_recursive( node* root ) {
	node* current = root ;
	if( current ) {
		printf("%d \n",current->value ) ;
		bfs_recursive( current->left_child ) ;
		bfs_recursive( current->right_child ) ;

	}
	
}

/* inserts a new node */
node* insert( node* root, int value ) {
	if( !root ) {
		root = ( node* )malloc( sizeof( int ) ) ;
		root->value = value ;
		root->left_child = ( node* )NULL ;
		root->right_child = ( node* )NULL ;
		return root ;
	}
	else {
		if( value < root->value ) {
			root->left_child = insert( root->left_child,value ) ;
			return root ;
		}
		else {
			root->right_child = insert( root->right_child,value ) ;
			return root ;
		}

	}

}

node* initialize_tree( int arr[], int size ) {
	node* root = NULL ;
	int i ;
	for( i = 0 ; i < size ; i++ ) {
		root = insert( root,arr[i] ) ;
	}
	return root ;
}

int main( int argc,char** argv ) {
	int arr[] = { 1,4,2,4 } ;
	node* root = initialize_tree( arr,5 ) ;
	bfs_recursive( root ) ;
	return 0 ;
}
