import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { CollectHolerComponent } from './collect-holer.component';

describe('CollectHolerComponent', () => {
  let component: CollectHolerComponent;
  let fixture: ComponentFixture<CollectHolerComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ CollectHolerComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(CollectHolerComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
