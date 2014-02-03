using UnityEngine;
using System.Collections;

public class Cat : MonoBehaviour {

	// The cat can be in differents states:
	// - idle (sitting somewhere)
	// - sleeping 
	// - scratching its nails
	// - walking (walking around or following the player)
	// - cathing some bees
	// - having fun with some boxes
	// [ *** ]
	// - playing with wool
	// ...
	
	// The distance between the cat & the player required to move-up the cat near the player.
	public float distanceToMove = 5.0f;
	// The distance between the cat & the player required to stop moving-up the cat near the player.
	public float distanceAroundPlayer = 1.5f;

	// The speed of the cat.
	public float speed = 2.0f;

	// The minimum & maximum time by state for the cat.
	public float minTimeByState = 5;
	public float maxTimeByState = 10;
	
	// Reference to the player's transform to calculate the distance between the player and the cat.
	private Transform player;	
	// The direction of the cat, right or left.
	private int direction = 1;
	// The animator containing the states of the cat
	private Animator animator;
	// The triggers to allow to pass from one to another state of the cat
	private string[] triggers = {"Walking", "Idleing", "Sleeping", "Catchingbee", "Scratching", "Indabox"}; 

	private float nextLocationToGo;
	// actual state 
	// 0 - Walking
	// 1 - Idleing
	// 2 - Sleeping
	// 3 - Catchingbee
	// 4 - Scratching
	// 5 - Indabox
	private int currentState;
	private float timeDoingSameThing = 0;
	private float timeStartingDoingSameThing = 0;
	
	// This function will move the skeleton toward the player, turning the sprite in the good direction.
	void moveTowardPlayer() {
		if (transform.position.x > player.position.x) {
			direction = -1;
		} else {
			direction = 1;
		}
		transform.localScale = new Vector3 (direction, 1, 1);
		transform.Translate (direction * speed * Time.deltaTime, 0, 0);		
	}

	// Use this for initialization
	void Start () {
		// Setting up the reference to player
		player = GameObject.FindGameObjectWithTag("GD").transform;
		animator = GetComponent<Animator>();
		nextLocationToGo = transform.position.x;
	}
	
	// Update is called once per frame
	void Update () {
		// Distance between the cat & the player
		float xDistance = Mathf.Abs (transform.position.x - player.position.x);
		if (xDistance > distanceToMove) { 
			// The cat wants to go near the player, between (player - distanceToStopMoving) to (player + distanceToStopMoving)
			nextLocationToGo = Random.Range (player.position.x - distanceAroundPlayer, player.position.x + distanceAroundPlayer);
			if (transform.position.x > player.position.x) {
					direction = -1;
			} else {
					direction = 1;
			}
			animator.SetTrigger("Walking");
			transform.localScale = new Vector3 (direction, 1, 1);
			transform.Translate (direction * speed * Time.deltaTime, 0, 0);
		} else if ((direction == -1 && transform.position.x > nextLocationToGo) || (direction == 1 && transform.position.x < nextLocationToGo)) {
			// The cat is not that far away from the player and is going to a specific location to change its states.
			animator.SetTrigger("Walking");
			transform.localScale = new Vector3 (direction, 1, 1);
			transform.Translate (direction * speed * Time.deltaTime, 0, 0);
		} else {
			// The cat is on any state, for an amount of time, and will do it untill the player goes away from the cat.
			if (Time.time - timeStartingDoingSameThing > timeDoingSameThing ) {
				currentState = Mathf.RoundToInt(Random.value * (triggers.Length-1));
				animator.SetTrigger(triggers[currentState]);
				timeDoingSameThing = Random.Range (minTimeByState, maxTimeByState);
				timeStartingDoingSameThing = Time.time;
			} else {
				//
			}
			doCurrentState();
		}
	}

	// actual state 
	// 0 - Walking
	// 1 - Idleing
	// 2 - Sleeping
	// 3 - Catchingbee
	// 4 - Scratching
	// 5 - Indabox
	void doCurrentState() {
		print ("currentState"+currentState);
		switch (currentState) {
		case 0:
			walking();
			break;
		case 1:
			idleing ();
			break;
		case 2:
			sleeping();
			break;
		case 3:
			catchingbee();
			break;
		case 4:
			scratching();
			break;
		case 5:
			indabox();
			break;
		default:
			break;
		}
	}
	
	void walking () {
		transform.localScale = new Vector3 (direction, 1, 1);
		transform.Translate (direction * speed * Time.deltaTime, 0, 0);
	}
	
	void idleing () {
	}

	void indabox () {
	}

	void sleeping () {
	}

	void catchingbee () {
	}

	void scratching () {
	}


}
