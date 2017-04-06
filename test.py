import tensorflow as tf

def pseudo_inverse(A):
	A_trans = tf.matrix_transpose(A)
	A_trans_A = tf.matmul(A_trans,A)
	A_inverse = tf.matrix_inverse(A_trans_A)
	return tf.matmul(A_inverse, A_trans)


if __name__ == "__main__":
    pseudo_inverse([[1,2],[3,4]])