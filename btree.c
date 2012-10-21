#include <stdio.h>
typedef struct {

	struct node* left_child ;
	struct node* right_child ;
	int value ;

} node ;

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
		printf("hehe\n") ;
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
		insert( root,arr[i] ) ;
	}
	return root ;
}

int main( int argc,char** argv ) {
	int arr[] = { 1,2,3,4,5 } ;
	node* root = initialize_tree( arr,5 ) ;
	bfs_recursive( root ) ;
	return 0 ;
}
