using UnityEngine;
using System.Collections;

public class LifeManager : MonoBehaviour {

	public int initialHP =2;
	private int currentHP;

	// Use this for initialization
	void Start () {
		this.currentHP = this.initialHP;
	}
	
	public void hit(){

		currentHP --;
		Debug.Log ("Hit " + currentHP);
		if (currentHP <= 0) {
			Debug.Log ("LifeManager : Destroy");
			GameObject.Destroy(this.gameObject);		
		}
	}
}
