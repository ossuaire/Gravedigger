using UnityEngine;
using System.Collections;

public class GravediggerCtrl : MonoBehaviour {

	public float moveForce = 500.0f;
	public float jumpForceInit = 130.0f;
	public float jumpForcePlus = 30.0f;
	public float slowForce = 100.0f;
	public string axisName = "Horizontal";
	public string jumpButton = "Jump";
	public int maxSpeed = 4;

	public float jumpDelay = 0.5f;
	private float jumpTimer =0;

	public float speedY=0.0f;

	private bool grounded;
	private Transform groundCheckL, groundCheckR;

	
	private Animator anim;

	// Use this for initialization
	void Start () {
		anim = GetComponent<Animator> ();
		groundCheckL = transform.FindChild("groundCheckL");
		groundCheckR = transform.FindChild("groundCheckR");

	}
	
	// Update is called once per frame
	void Update () {
		grounded = Physics2D.Linecast (transform.position, groundCheckR.position,1 << LayerMask.NameToLayer("Background"))
			|| Physics2D.Linecast (transform.position, groundCheckL.position,1 << LayerMask.NameToLayer("Background"));
		anim.SetBool ("Grounded", grounded);
		float inputX = Input.GetAxis (axisName);
		anim.SetFloat ("SpeedX", Mathf.Abs(inputX));
		//transform.position += transform.right * inputX * speed * Time.deltaTime;
		if (inputX != 0 && rigidbody2D.velocity.x > -maxSpeed && rigidbody2D.velocity.x < maxSpeed) { 
			rigidbody2D.AddForce (transform.right * inputX * moveForce * Time.deltaTime);
		}
		if (inputX == 0) {
			if(rigidbody2D.velocity.x > 0.1){
				rigidbody2D.AddForce(-transform.right * rigidbody2D.velocity.x * slowForce * Time.deltaTime);
			}else if (rigidbody2D.velocity.x < -0.1) {
				rigidbody2D.AddForce(-transform.right * rigidbody2D.velocity.x * slowForce * Time.deltaTime);
			}

		}

		// Sprite looking right place
		if (inputX < 0) {
			Vector3 newScale= transform.localScale;
			newScale.x= -1.0f;
			transform.localScale=newScale;
		} else if (inputX > 0) {
			Vector3 newScale= transform.localScale;
			newScale.x= 1.0f;
			transform.localScale=newScale;
		}
	
		// Jump
		jumpTimer -= Time.deltaTime;
		if (Input.GetAxis (jumpButton)>0 ){
		    if(grounded && jumpTimer<0) { // InitJump
				jumpTimer=jumpDelay;
				rigidbody2D.AddForce (transform.up * jumpForceInit);
				anim.SetTrigger ("Jump");
			} else if(jumpTimer>0){ // Press Longer Jump Higher
				rigidbody2D.AddForce (transform.up * jumpForcePlus*jumpTimer);
			}
		}
		this.speedY = rigidbody2D.velocity.y;
		anim.SetFloat ("SpeedY", this.speedY);

	}
}
