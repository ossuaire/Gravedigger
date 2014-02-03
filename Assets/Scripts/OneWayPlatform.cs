using UnityEngine;
using System.Collections;

public class OneWayPlatform : MonoBehaviour {
	public GravediggerCtrl gd;
	private Collider2D[] cols;
	// Use this for initialization
	void Start () 
	{
		this.cols=FindObjectsOfType<Collider2D> ();
	}
	
	// Update is called once per frame
	void Update () 
	{
		foreach (Collider2D col in cols) 
		{
			col.enabled = gd.speedY <= 0;
		}
	}
}
