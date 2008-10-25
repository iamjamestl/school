/*
 * InvalidNffException.java
 * James Lee <jlee23@umbc.edu>
 * 
 * Simple exception for handling errors while parsing NFF files.
 */
package org.thestaticvoid.raytracer;

public class InvalidNffException extends Exception {
	private static final long serialVersionUID = 1L;

	public InvalidNffException(String exception) {
		super(exception);
	}
}
