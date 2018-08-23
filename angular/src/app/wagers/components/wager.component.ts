import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-wager',
  templateUrl: '../templates/wager.component.html'
})
export class WagerComponent implements OnInit {
  public items = [1, 2, 3, 4, 5, 6];

  constructor() { }

  ngOnInit() {
  }

}
