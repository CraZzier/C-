import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { BadaniaComponent } from './badania.component';

describe('BadaniaComponent', () => {
  let component: BadaniaComponent;
  let fixture: ComponentFixture<BadaniaComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ BadaniaComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(BadaniaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
